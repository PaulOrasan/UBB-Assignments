package socialnetwork.repository.memory;

import socialnetwork.domain.Entity;
import socialnetwork.domain.validators.Validator;
import socialnetwork.repository.Repository;

import java.util.HashMap;
import java.util.Map;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID,E> {

    Map<ID,E> entities;

    public InMemoryRepository() {
        entities=new HashMap<ID,E>();
    }

    @Override
    public E findOne(ID id){
        if (id==null)
            throw new IllegalArgumentException("id must be not null");
        return entities.get(id);
    }

    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public E save(E entity) {
        if (entity==null)
            throw new IllegalArgumentException("entity must be not null");
        if(entities.get(entity.getId()) != null) {
            return entity;
        }
        else
            entities.put(entity.getId(),entity);
        return null;
    }

    @Override
    public E delete(ID id) {
        E result = null;
        if (entities.containsKey(id)) {
            result = entities.get(id);
            entities.remove(id);
        }
        return result;
    }

    @Override
    public E update(E entity) {

        if(entity == null)
            throw new IllegalArgumentException("entity must be not null!");

        if(entities.get(entity.getId()) != null) {
            entities.put(entity.getId(), entity);
            return null;
        }
        return entity;
    }

    @Override
    public void syncContent(){}

}
